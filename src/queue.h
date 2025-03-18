#pragma once

#include <mutex>
#include <optional>
#include <queue>
#include <shared_mutex>

template <typename T> 
class safe_queue_no_block {
private:
	std::queue<T> queue_;
	mutable std::shared_mutex mtx_;

public:
	void enqueue(const T &value) {
		std::unique_lock<std::shared_mutex> lock(mtx_);
		queue_.push(value);
	}

	std::optional<T> dequeue() {
		std::shared_lock<std::shared_mutex> lock(mtx_);
		if (queue_.empty())
			return std::nullopt;
		T value = queue_.front();
		queue_.pop();
		return value;
	}
};