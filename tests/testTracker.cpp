#include <memory>

#include <gtest/gtest.h>

#include "PTAM/Tracker.hpp"


namespace {

class TrackerTest : public ::testing::Test {
public:
  void SetUp() override {}

  void TearDown() override {}

  PTAM::Tracker* m_pTracker;

};

TEST(TrackerTest, DefaultConstructor) {
  //CVD::ImageRef imageRef;
  //PTAM::ATANCamera camera();
  //PTAM::Map map;
  //PTAM::MapMaker maker();

  //m_pTracker = std::make_unique<PTAM::Tracker>(imageRef, camera, map , maker);
  //EXPECT_EQ(1, 1);
}

} // namespace
