#pragma once
#include <vector>
#include <type_traits>



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
	template<typename T, typename... Others>
	struct is_any : std::disjunction<std::is_same<T, Others>...>
	{
	};
	template<typename T>
	struct is_cuttable : is_any<T, int, char, int8_t, int16_t>
	{
	};

	template<typename T>
	decltype(typename std::enable_if<!(is_cuttable<T>::value), T>::type(), std::vector<T>())
	conv1d(const std::vector<T> &in) {
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
	
	template<typename T>
	decltype(typename std::enable_if<(is_cuttable<T>::value ), T>::type(), std::vector<T>())
		conv1d(const std::vector<T> &in) {
		std::vector<T> result;
		for (int i = 0; i <= in.size() - weights.size(); i++) {
			int32_t tmp{};
			for (int j = 0; j < weights.size(); j++) {
				tmp += weights[weights.size() - j - 1] * in[i + j];
			}
			if (tmp > std::numeric_limits<T>::max()) {
				tmp = std::numeric_limits<T>::max();
			}
			else if (tmp < std::numeric_limits<T>::min()) {
				tmp = std::numeric_limits<T>::min();
			}
			result.push_back(tmp);

		}
		return result;
	}

	~Filter() {}
};