#include <mutex>

class Singleton {
public:
    // Static method to get the single instance
    static Singleton& getInstance() {
        // Use a one-time initialization flag
        static std::once_flag flag;
        // Call the lambda function only once
        std::call_once(flag, []() {
            // Create a unique pointer to the Singleton instance
            instance = std::make_unique<Singleton>();
        });
        // Return a reference to the instance
        return *instance;
    }

    // Public method to perform some action
    void doSomething() {
        std::cout << "Doing something..." << std::endl;
    }

private:
    // Default constructor and destructor
    Singleton() = default;
    ~Singleton() = default;

    // Static unique pointer to the single instance
    static std::unique_ptr<Singleton> instance;
};

// Initialize the static member
std::unique_ptr<Singleton> Singleton::instance;