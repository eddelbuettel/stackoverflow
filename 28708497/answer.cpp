// updated C++17 answer for old question of 'constexpr to concatenate two or more char strings'

#include <initializer_list>

// we cannot return a char array from a function, therefore we need a wrapper
template <unsigned N>
struct String {
  char c[N];
};

template<unsigned ...Len>
constexpr auto cat(const char (&...strings)[Len]) {
  constexpr unsigned N = (... + Len) - sizeof...(Len);
  String<N + 1> result = {};
  result.c[N] = '\0';

  char* dst = result.c;
  for (const char* src : {strings...}) {
    for (; *src != '\0'; src++, dst++) {
      *dst = *src;
    }
  }
  return result;
}

// can be used to build other constexpr functions
template<unsigned L>
constexpr auto makeCopyright(const char (&author)[L]) {
  return cat("\xC2\xA9 ", author);
}

constexpr char one[] = "The desert was the apotheosis of all deserts";
constexpr char two[] = "huge, standing to the sky";

constexpr auto three = cat(
  cat(one, ", ", two).c, // can concatenate recursively
  " ",
  "for what looked like eternity in all directions."); // can use in-place literals

constexpr auto phrase = cat(
  three.c, // can reuse existing cats
  "\n",
  makeCopyright("Stephen King").c);

#include <cstdio>
int main() {
  puts(phrase.c);
  return 0;
}
