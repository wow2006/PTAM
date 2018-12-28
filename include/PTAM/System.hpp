// -*- c++ -*-
// Copyright 2008 Isis Innovation Limited
//
// System.h
//
// Defines the System class
//
// This stores the main functional classes of the system, like the
// mapmaker, map, tracker etc, and spawns the working threads.
//
#ifndef __SYSTEM_H
#define __SYSTEM_H
#include "GLWindow2.h"
#include "VideoSource.h"

#include <cvd/byte.h>
#include <cvd/image.h>
#include <cvd/rgb.h>

class ATANCamera;
class Map;
class MapMaker;
class Tracker;
class ARDriver;
class MapViewer;


namespace PTAM {
/** 
* @brief 
*/
class System {
public:
  /** 
  * @brief 
  */
  System();

  /** 
  * @brief 
  */
  void Run();

private:
  VideoSource mVideoSource;

  GLWindow2 mGLWindow;

  CVD::Image<CVD::Rgb<CVD::byte>> mimFrameRGB;

  CVD::Image<CVD::byte> mimFrameBW;

  Map *mpMap;

  MapMaker *mpMapMaker;

  Tracker *mpTracker;

  ATANCamera *mpCamera;

  ARDriver *mpARDriver;

  MapViewer *mpMapViewer;

  bool mbDone;

  /** 
  * @brief 
  * 
  * @param ptr
  * @param sCommand
  * @param sParams
  */
  static void GUICommandCallBack(void *ptr, std::string sCommand,
                                 std::string sParams);
};

} // namespace PTAM
#endif
