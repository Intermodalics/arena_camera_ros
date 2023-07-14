#include <sensor_msgs/image_encodings.h>

namespace arena_camera {
  namespace image_encodings {
    using namespace sensor_msgs::image_encodings;

    // Additional encodings
    const std::string CONFIDENCE16 = "confidence16";
    const std::string COORD3D_ABC16 = "coord3d_abc16";
    const std::string COORD3D_ABCY16 = "coord3d_abcy16";

    // Patched versions of helper functions
    static inline bool isMono(const std::string &encoding) {
      return sensor_msgs::image_encodings::isMono(encoding) || encoding == CONFIDENCE16;
    }

    static inline int bitDepth(const std::string& encoding) {
      if (encoding == CONFIDENCE16 || encoding == COORD3D_ABC16 || encoding == COORD3D_ABCY16) return 16;
      return sensor_msgs::image_encodings::bitDepth(encoding);
    }
  }
}