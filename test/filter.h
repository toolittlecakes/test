#pragma once
#include <vector>

template<typename T>
class Filter final {
	std::vector<T> weights;
public:
	Filter(const std::vector<T> &init_weights) {
		weights = init_weights;
	}
	Filter(std::vector<T> &&init_weights) {
		weights = init_weights;
	}

	std::vector<T> conv1d(std::vector<T> &in) {
		std::vector<T> result;
		for (int i = 0; i <= in.size() - weights.size(); i++) {
			T tmp{};
			for (int j = 0; j < weights.size(); j++) {
				tmp += weights[weights.size() - j - 1] * in[i + j];
			}
			result.push_back(tmp);

		}
		return result;
	}

	~Filter() {}
};