#include "../ecs/coordinator.cpp"

class Simulator {
    public:
        void begin_simulation();
    private:
        Coordinator coordinator;
};