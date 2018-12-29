//-*- C++ -*-
// Copyright 2008 Isis Innovation Limited
//
// This header declares the Tracker class.
// The Tracker is one of main components of the system,
// and is responsible for determining the pose of a camera
// from a video feed. It uses the Map to track, and communicates
// with the MapMaker (which runs in a different thread)
// to help construct this map.
//
// Initially there is no map, so the Tracker also has a mode to
// do simple patch tracking across a stereo pair. This is handled
// by the TrackForInitialMap() method and associated sub-methods.
// Once there is a map, TrackMap() is used.
//
// Externally, the tracker should be used by calling TrackFrame()
// with every new input video frame. This then calls either
// TrackForInitialMap() or TrackMap() as appropriate.
#pragma once

#include <list>
#include <sstream>
#include <string>
#include <vector>

#include "PTAM/MiniPatch.hpp"
#include "PTAM/Relocaliser.hpp"

#include "PTAM/ATANCamera.hpp"
#include "PTAM/KeyFrame.hpp"
#include "PTAM/Map.hpp"
#include "PTAM/MapMaker.hpp"

namespace PTAM {

class TrackerData;
class SmallBlurryImage;

/**
 * @brief This struct is used for initial correspondences of the first
 * stereo pair.
 */
struct Trail {
  MiniPatch mPatch;
  CVD::ImageRef irCurrentPos;
  CVD::ImageRef irInitialPos;
};

class Tracker {
public:
  /**
   * @brief
   *
   * @param irVideoSize
   * @param c
   * @param m
   * @param mm
   */
  Tracker(CVD::ImageRef irVideoSize, const ATANCamera &c, Map &m, MapMaker &mm);

  /**
   * @brief TrackFrame is the main working part of the tracker: call this every
   * frame.
   *
   * @param imFrame
   * @param bDraw
   */
  void TrackFrame(CVD::Image<CVD::byte> &imFrame, bool bDraw);

  /**
   * @brief
   *
   * @return
   */
  SE3<> GetCurrentPose() { return mse3CamFromWorld; }

  // Gets messages to be printed on-screen for the user.
  std::string GetMessageForUser();

protected:
  KeyFrame mCurrentKF; // The current working frame as a keyframe struct

  /**
   *  @name The major components to which the tracker needs access:
   *  @{
   */
  Map &mMap;                // The map, consisting of points and keyframes
  MapMaker &mMapMaker;      // The class which maintains the map
  ATANCamera mCamera;       // Projection model
  Relocaliser mRelocaliser; // Relocalisation module
  /** @} */

  CVD::ImageRef mirSize; // Image size of whole image

  /**
   * @brief Restart from scratch. Also tells the mapmaker to reset itself.
   */
  void Reset();

  /**
   * @brief Draws the reference grid
   */
  void RenderGrid();

  // The following members are used for initial map tracking (to get the first
  // stereo pair and correspondences):
  /**
   * @brief This is called by TrackFrame if there is not a map yet.
   */
  void TrackForInitialMap();

  enum {
    TRAIL_TRACKING_NOT_STARTED,
    TRAIL_TRACKING_STARTED,
    TRAIL_TRACKING_COMPLETE
  } mnInitialStage; // How far are we towards making the initial map?

  /**
   * @brief First frame of initial trail tracking. Called by TrackForInitialMap.
   */
  void TrailTracking_Start();

  /**
   * @brief Steady-state of initial trail tracking. Called by
   * TrackForInitialMap.
   *
   * @return
   */
  int TrailTracking_Advance();

  std::list<Trail> mlTrails; // Used by trail tracking
  KeyFrame mFirstKF;         // First of the stereo pair
  KeyFrame mPreviousFrameKF; // Used by trail tracking to check married matches

  // Methods for tracking the map once it has been made:
  /**
   * @brief Called by TrackFrame if there is a map.
   */
  void TrackMap();

  /**
   * @brief Heuristics to choose between good, poor, bad.
   */
  void AssessTrackingQuality();

  /**
   * @brief Decaying velocity motion model applied prior to TrackMap
   */
  void ApplyMotionModel();

  /**
   * @brief Motion model is updated after TrackMap
   */
  void UpdateMotionModel();

  /**
   * @brief Finds points in the image
   *
   * @param vTD
   * @param nRange
   * @param nFineIts
   *
   * @return
   */
  int SearchForPoints(std::vector<TrackerData *> &vTD, int nRange,
                      int nFineIts);

  /**
   * @brief Updates pose from found points.
   *
   * @param vTD
   * @param dOverrideSigma
   * @param bMarkOutliers
   *
   * @return
   */
  Vector<6> CalcPoseUpdate(std::vector<TrackerData *> vTD,
                           double dOverrideSigma = 0.0,
                           bool bMarkOutliers = false);

  SE3<> mse3CamFromWorld; // Camera pose: this is what the tracker updates every
  // frame.
  SE3<> mse3StartPos; // What the camera pose was at the start of the frame.
  Vector<6> mv6CameraVelocity;         // Motion model
  double mdVelocityMagnitude;          // Used to decide on coarse tracking
  double mdMSDScaledVelocityMagnitude; // Velocity magnitude scaled by relative
  // scene depth.
  bool mbDidCoarse; // Did tracking use the coarse tracking stage?

  bool mbDraw; // Should the tracker draw anything to OpenGL?

  /**
   * @name Interface with map maker:
   * @{ */

  int mnFrame;               // Frames processed since last reset
  int mnLastKeyFrameDropped; // Counter of last keyframe inserted.

  /**  @} */

  /**
   * @brief Gives the current frame to the mapmaker to use as a keyframe
   */
  void AddNewKeyFrame();

  /**
   * @name Tracking quality control:
   * @{ */
  int manMeasAttempted[LEVELS];
  int manMeasFound[LEVELS];
  enum { BAD, DODGY, GOOD } mTrackingQuality;
  int mnLostFrames;
  /**  @} */

  /**
   * @name Relocalisation functions:
   * @{ */

  /**
   * @brief Called by TrackFrame if tracking is lost.
   *
   * @return
   */
  bool AttemptRecovery();

  /**
   * @brief Always use coarse tracking after recovery!
   */
  bool mbJustRecoveredSoUseCoarse;

  /**  @} */

  /**
   * @name Frame-to-frame motion init:
   * @{ */
  SmallBlurryImage *mpSBILastFrame;
  SmallBlurryImage *mpSBIThisFrame;
  /**  @} */

  void CalcSBIRotation();

  Vector<6> mv6SBIRot;
  bool mbUseSBIInit;

  // User interaction for initial tracking:
  bool mbUserPressedSpacebar;

  std::ostringstream mMessageForUser;

  /**
   * @brief GUI interface:
   *
   * @param sCommand
   * @param sParams
   */
  void GUICommandHandler(std::string sCommand, std::string sParams);

  /**
   * @brief
   *
   * @param ptr
   * @param sCommand
   * @param sParams
   */
  static void GUICommandCallBack(void *ptr, std::string sCommand,
                                 std::string sParams);

  struct Command {
    std::string sCommand;
    std::string sParams;
  };
  std::vector<Command> mvQueuedCommands;
};

} // namespace PTAM
