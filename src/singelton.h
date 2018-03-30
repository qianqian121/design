// Singleton.hpp
class Singleton {
public:
    static Singleton& Instance() {
        static Singleton S;
        return S;
    }

private:
    Singleton();
    ~Singleton();
};




template<typename HeirT>
class Singleton
{
public:
    Singleton() = delete;

    Singleton(const Singleton &) = delete;

    Singleton &operator=(const Singleton &) = delete;

    static HeirT &instance()
    {
        static HeirT instance;
        return instance;
    }
};
