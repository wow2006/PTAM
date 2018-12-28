// -*- c++ -*-
// Copyright 2008 Isis Innovation Limited

#ifndef __GL_WINDOW_MENU_HPP
#define __GL_WINDOW_MENU_HPP

// A simple gvars-driven menu system for GLWindow2
// N.b. each GLWindowMenu class internally contains sub-menus

#include <map>
#include <vector>

#include <gvars3/gvars3.h>

#include "PTAM/GLWindow2.hpp"

namespace PTAM {

class GLWindowMenu {
public:
  /** 
  * @brief 
  * 
  * @param sName
  * @param sTitle
  */
  GLWindowMenu(std::string sName, std::string sTitle);

  /** 
  * @brief 
  */
  ~GLWindowMenu();

  /** 
  * @brief 
  * 
  * @param nTop
  * @param nHeight
  * @param nWidth
  * @param glw
  */
  void Render(int nTop, int nHeight, int nWidth, GLWindow2 &glw);

  /** 
  * @brief 
  * 
  * @param l
  * @param r
  * @param t
  * @param b
  */
  void FillBox(int l, int r, int t, int b);

  /** 
  * @brief 
  * 
  * @param l
  * @param r
  * @param t
  * @param b
  */
  void LineBox(int l, int r, int t, int b);

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
  * @brief 
  * 
  * @param button
  * @param state
  * @param x
  * @param y
  * 
  * @return 
  */
  bool HandleClick(int button, int state, int x, int y);

private:
  enum MenuItemType { Button, Toggle, Monitor, Slider };

  struct MenuItem {
    MenuItemType type;
    std::string sName;
    std::string sParam;
    std::string sNextMenu;
    GVars3::gvar2_int gvnIntValue; // Not used by all, but used by some
    int min;
    int max;
  };

  struct SubMenu {
    std::vector<MenuItem> mvItems;
  };

  std::map<std::string, SubMenu> mmSubMenus;
  std::string msCurrentSubMenu;
  std::string msName;
  std::string msTitle;

  int mnWidth;
  int mnMenuTop;
  int mnMenuHeight;
  int mnTextOffset;

  GVars3::gvar2_int mgvnEnabled;
  GVars3::gvar2_int mgvnMenuItemWidth;
  GVars3::gvar2_int mgvnMenuTextOffset;

  int mnLeftMostCoord;
};

} // namespace PTAM

#endif
