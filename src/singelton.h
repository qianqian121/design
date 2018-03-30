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


/*Singletons solve one (and only one) problem.

Resource Contention.

If you have some resource that

(1) can only have a single instance, and

(2) you need to manage that single instance,

you need a singleton.

There aren't many examples. A log file is the big one. You don't want to just abandon a single log file. You want to flush, sync and close it properly. This is an example of a single shared resource that has to be managed.

It's rare that you need a singleton. The reason they're bad is that they feel like a global and they're a fully paid up member of the GoF Design Patterns book.

When you think you need a global, you're probably making a terrible design mistake.*/


/*Paraphrased from Brian Button:

They are generally used as a global instance, why is that so bad? Because you hide the dependencies of your application in your code, instead of exposing them through the interfaces. Making something global to avoid passing it around is a code smell.
They violate the single responsibility principle: by virtue of the fact that they control their own creation and lifecycle.
They inherently cause code to be tightly coupled. This makes faking them out under test rather difficult in many cases.
They carry state around for the lifetime of the application. Another hit to testing since you can end up with a situation where tests need to be ordered which is a big no no for unit tests. Why? Because each unit test should be independent from the other.*/
