//
// Propagator Pattern - Subjects can add, remove, update, and notify observers
//
// Created by Michael Lewis on 8/16/23.
//

#ifndef ADVANCED_CPP_AND_MODERN_DESIGN_PROPAGATOR_HPP
#define ADVANCED_CPP_AND_MODERN_DESIGN_PROPAGATOR_HPP

#include <list>
#include <memory>

class Propagator
{
private:
    std::list<std::shared_ptr<Propagator>> observables;
public:
    Propagator();
    Propagator(const Propagator& other) = default;
    Propagator(Propagator&& other) = default;
    virtual ~Propagator() = default;

    // Operator Overloads
    Propagator& operator=(const Propagator& other) = default;
    Propagator& operator=(Propagator&& other) = default;

    virtual void notify();

    virtual void addObservable(std::shared_ptr<Propagator>& observable);
    virtual void deleteObservable(std::shared_ptr<Propagator>& observable);
    virtual void update(const Propagator& observable) = 0;
};


#endif //ADVANCED_CPP_AND_MODERN_DESIGN_PROPAGATOR_HPP
