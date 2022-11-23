#include <vector>

class Encoder {
   public:
    std::vector<int> NRZ_L(std::vector<int> bits);
    std::vector<int> NRZ_I(std::vector<int> bits);
    std::vector<int> Manchester(std::vector<int> bits);
    std::vector<int> Differential_Manchester(std::vector<int> bits);
    std::vector<int> AMI(std::vector<int> bits);
};

std::vector<int> Encoder::NRZ_L(std::vector<int> bits) {
    std::vector<int> result;
    for (auto b : bits) {
        if (b == 1) {
            result.push_back(1);
        } else {
            result.push_back(-1);
        }
    }
    return result;
}

std::vector<int> Encoder::NRZ_I(std::vector<int> bits) {
    std::vector<int> result;
    bool flag = true;
    for (auto b : bits) {
        if (b == 1) {
            result.push_back(flag ? -1 : 1);
            flag = !flag;
        } else {
            result.push_back(flag ? 1 : -1);
        }
    }
    return result;
}

std::vector<int> Encoder::Manchester(std::vector<int> bits) {
    std::vector<int> result;
    for (auto b : bits) {
        if (b == 1) {
            result.push_back(-1);
            result.push_back(1);
        } else {
            result.push_back(1);
            result.push_back(-1);
        }
    }
    return result;
}

std::vector<int> Encoder::Differential_Manchester(std::vector<int> bits) {
    std::vector<int> result;
    bool flag = true;
    for (auto b : bits) {
        if (b == 1) {
            result.push_back(flag ? 1 : -1);
            result.push_back(flag ? -1 : 1);
            flag = !flag;
        } else {
            result.push_back(flag ? -1 : 1);
            result.push_back(flag ? 1 : -1);
        }
    }
    return result;
}

std::vector<int> Encoder::AMI(std::vector<int> bits) {
    std::vector<int> result;
    int flag = true;
    for (auto b : bits) {
        if (b == 1) {
            result.push_back(flag ? 1 : -1);
            flag = !flag;
        } else {
            result.push_back(0);
        }
    }
    return result;
}
