#include <iostream>
#include <map>
#include <memory>
#include <mutex>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <functional>

#include "solution.h"

using namespace std;

template <typename T>
class Solution_T : public Solution {
    
    template <typename ...ArgType>
    Inject(ArgType&&... Args){
        target(Args);
    }

};

int main() {
}
