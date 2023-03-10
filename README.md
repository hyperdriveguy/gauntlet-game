# Overview

This is my head-first dive into C++. I'm trying to use several features of the language that seem useful
or will be applicable in development of C++ projects (i.e. Makefile).

This is a small game where you battle randomly generated enemies one after another.
Think of it as a bullet-hell combined with an turn based combat game.

I wanted to take a concept I was somewhat familar with and implement it in a new programming language
that I haven't really used the features of before.

[Gameplay](https://youtu.be/rNHRTZYgudI)

[Software Explanation](https://youtu.be/u7pW38egm6E)

# Development Environment

This project was developed using Kate text editor with GDB extensions for debugging.
The compiler intended to be used is `g++` with `make`.

The language is C++ and tries to make use of exclusively the standard library as much as possible.
The eventual goal is to make it so this project can be ported to a microcontroller.

# Useful Websites

Here are some sites I've found useful while developing this project:

- [cplusplus.com](https://cplusplus.com/reference/)
- [ChatGPT (Yes, really)](https://chat.openai.com)

# Future Work

- Implement experience gain
- Don't use a map for base stats
- Use ncurses instead of `cout` and `cin`
- Modify data for a more balanced game
