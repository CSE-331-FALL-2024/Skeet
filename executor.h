#pragma once
#ifndef EXECUTOR_H // This includes a guard to prevent erros where this file gets included more than once
#define EXECUTOR_H // If the above has not been defined during compilation yet, then define. If it has already been defined, then ignore this file.

#include <vector>
#include "order.h" // Include the base Order class

class Executor {
private:
	std::vector<Order*> history; // make a vector so we can keep track of the orders executed, giving a history of the orders in case we want to undo them

public:
    // Execute the given order
    void execute(Order* order)
    {
		order->execute();
		history.push_back(order); // history option to track orders
    }

    // Undo the last executed order (optional)
    void undo()
    {
		// Stub for now
		// undo the last order
		return;
    }

    // Destructor to clean up any remaining orders
    ~Executor()
    {
		// Stub
		return;
    }
};

#endif // EXECUTOR_H // End of the guard and definition
