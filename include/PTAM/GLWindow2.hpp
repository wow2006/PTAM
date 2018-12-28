// -*- c++ -*-
// Copyright 2008 Isis Innovation Limited
#ifndef __GL_WINDOW_2_H
#define __GL_WINDOW_2_H
//
//  A class which wraps a CVD::GLWindow and provides some basic
//  user-interface funtionality: A gvars-driven clickable menu, and a
//  caption line for text display. Also provides some handy GL helpers
//  and a wrapper for CVD's text display routines.

#include <TooN/TooN.h>
#include <cvd/glwindow.h>


namespace PTAM {

class GLWindowMenu;

class GLWindow2 : public CVD::GLWindow, public CVD::GLWindow::EventHandler {
public:
  /** 
  * @brief 
  * 
  * @param irSize
  * @param sTitle
  */
  GLWindow2(CVD::ImageRef irSize, std::string sTitle);

  /** 
  * @brief The preferred event handler..
  */
  void HandlePendingEvents();

  /** 
  * @brief Menu interface:
  * 
  * @param sName
  * @param sTitle
  */
  void AddMenu(std::string sName, std::string sTitle);

  /** 
  * @brief 
  */
  void DrawMenus();

  /** 
  * @brief Some OpenGL helpers:
  */
  void SetupViewport();

  void SetupVideoOrtho();

  void SetupUnitOrtho();

  void SetupWindowOrtho();

  void SetupVideoRasterPosAndZoom();

  
  /** 
  * @brief Text display functions:
  * 
  * @param irPos
  * @param s
  */
  void PrintString(CVD::ImageRef irPos, std::string s);

  void DrawCaption(std::string s);

  /** 
  * @brief Map viewer mouse interface:
  * 
  * @return 
  */
  std::pair<TooN::Vector<6>, TooN::Vector<6>> GetMousePoseUpdate();

protected:
  /** 
  * @brief 
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

  /** 
  * @brief User interface menus:
  */
  std::vector<GLWindowMenu *> mvpGLWindowMenus;

  CVD::ImageRef mirVideoSize; // The size of the source video material.

  /** 
  * @brief Event handling routines:
  * 
  * @param 
  * @param key
  */
  virtual void on_key_down(GLWindow &, int key);

  /** 
  * @brief 
  * 
  * @param win
  * @param where
  * @param state
  */
  virtual void on_mouse_move(GLWindow &win, CVD::ImageRef where, int state);

  /** 
  * @brief 
  * 
  * @param win
  * @param where
  * @param state
  * @param button
  */
  virtual void on_mouse_down(GLWindow &win, CVD::ImageRef where, int state,
                             int button);

  /** 
  * @brief 
  * 
  * @param win
  * @param event
  */
  virtual void on_event(GLWindow &win, int event);

  CVD::ImageRef mirLastMousePos;

  // Storage for map viewer updates:
  TooN::Vector<6> mvMCPoseUpdate;
  TooN::Vector<6> mvLeftPoseUpdate;
};

} // namespace PTAM

#endif
