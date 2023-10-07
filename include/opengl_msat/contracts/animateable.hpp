#ifndef OPENGL_MSAT_ANIMATEABLE_HPP
#define OPENGL_MSAT_ANIMATEABLE_HPP

template <typename T>
class Animateable {
public:
    virtual void animate(float pct, T from, T to) = 0;

};

#endif
