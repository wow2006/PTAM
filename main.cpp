// Copyright 2008 Isis Innovation Limited
// This is the main extry point for PTAM
#include <cstdlib>
#include <iostream>

#include <gvars3/instances.h>

#include "PTAM/Systam.hpp"

using namespace GVars3;

int main() {
  std::cout << "  Welcome to PTAM \n";
  std::cout << "  --------------- \n";
  std::cout << "  Parallel tracking and mapping for Small AR workspaces\n";
  std::cout << "  Copyright (C) Isis Innovation Limited 2008 \n";
  std::cout << "\n  Parsing settings.cfg ....\n";

  // Parse Settings file
  GUI.LoadFile("settings.cfg");

  // Start parsing of the console input
  GUI.StartParserThread();

  atexit(GUI.StopParserThread);

  try {
    PTAM::System s;
    s.Run();
  } catch (CVD::Exceptions::All e) {
    std::cout << "\n!! Failed to run system; got exception. \n";
    std::cout << "   Exception was: \n";
    std::cout << e.what << endl;
  }
}
