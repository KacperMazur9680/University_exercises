#ifndef _H_STOPWATCH
#define _H_STOPWATCH

#include <string>
#include <sstream>
#include <chrono>

namespace km
{

	class Stopwatch {
		std::chrono::high_resolution_clock::time_point begin;
		std::chrono::high_resolution_clock::time_point end;

		std::string timeToString(const double value, const std::string& unit, const int width, const int precision) const {
			std::stringstream ss;
			ss.precision(precision);
			ss.width(width);
			ss << std::fixed << value;
			ss << unit;
			return ss.str();
		}

	public:

		enum class tu { aut, sec, ms, us, ns };

		void Start() noexcept {
			begin = std::chrono::high_resolution_clock::now();
		}

		void Stop() noexcept {
			end = std::chrono::high_resolution_clock::now();
		}

		long long int Time() const noexcept {
			return std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count();
		}

		std::string ToString(tu mode = tu::aut) const noexcept {

			long long int dt = Time();
			if (mode == tu::aut) {
				double t = 1.0e-9 * dt;
				if (t < 1e-7) mode = tu::ns;
				else if (t < 1e-4) mode = tu::us;
				else if (t < 1e-1) mode = tu::ms;
				else mode = tu::sec;
			}

			if (mode == tu::sec) return timeToString(1.0e-9 * dt, "s", 0, 3);
			else if (mode == tu::ms) return timeToString(1.0e-6 * dt, "ms", 0, 3);
			else if (mode == tu::us) return timeToString(1.0e-3 * dt, "us", 0, 3);
			else if (mode == tu::ns) return timeToString(1.0 * dt, "ns", 0, 3);
			else return "";
		}
	};

}	// namespace ap

#endif