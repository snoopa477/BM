#include<vector>

using namespace std;

enum class StepStatus {
    EMPTY, OBSTACLE, ANT, DOODLEBUG, ARTHORPODS, UNDEFINED
};

static vector<StepStatus> ALL_STEPSTATUS(
    { StepStatus::EMPTY,
    StepStatus::OBSTACLE,
    StepStatus::ANT,
    StepStatus::DOODLEBUG,
    StepStatus ::ARTHORPODS,
    StepStatus ::UNDEFINED });