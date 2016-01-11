#ifndef QUUX_H_

class Quux
{
private:
    static const int version_major;
    static const int version_minor;

public:
    Quux();
    int get_version() const;
    int quuxifier() const;
};

#endif // QUUX_H_
