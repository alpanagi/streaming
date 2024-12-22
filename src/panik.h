#ifndef _PANIK_H_
#define _PANIK_H_

#include <string>

namespace panik {
enum class Component {
  Sdl,
};

void crash(const Component &, const std::string &message);
} // namespace panik

#endif
