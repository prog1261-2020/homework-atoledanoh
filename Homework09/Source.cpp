//@author  <Alejandro Toledano>
//@version <1.0>
//
//@section Academic Integrity
//I certify that this work is solely my own and complies with
//NBCC Academic Integrity Policy (policy 1111)
//
//@section DESCRIPTION
//< Object Orientated Programming in C++ homework 09: Yielding and mutex. Consumers and producers.>
//
//@section LICENSE
//<any necessary attributions>
//
//Copyright 2020
//Permission to use, copy, modify, and/or distribute this software for
//any purpose with or without fee is hereby granted, provided that the
//above copyright notice and this permission notice appear in all copies.
//
//THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
//WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
//MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
//ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
//WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
//ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
//OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.

#include <iostream>
#include <thread>
#include <ctime>
#include <vector>
#include <mutex>
#include <atomic>
#include <chrono>
#include "WorkQueue.h"

std::atomic<bool> make_work(false);
WorkQueue jobs;
std::mutex cout_mutex;

void producer() {
	while (!make_work) {
		make_work = true;
		jobs.push(rand() % 100);
		cout_mutex.lock();
		std::this_thread::sleep_for(std::chrono::milliseconds(50));
		cout_mutex.unlock();
	}
}

void consumer(int id) {
	while (make_work) {
		make_work = false;
		if (jobs.size() == 0) {
			std::this_thread::yield();
		}
		else {
			int n = jobs.pop();
			int sz = jobs.size();
			cout_mutex.lock();
			std::cout << "Size: " << sz << " : " << id << " processed " << n << "\n";
			cout_mutex.unlock();
		}
	}
}

int main() {
	srand(time(0));
	std::vector<std::thread> producers;
	std::vector<std::thread> consumers;

	for (int i = 0; i < 40; ++i) {
		producers.push_back(std::thread(producer));
	}

	for (int i = 0; i < 40; ++i) {
		consumers.push_back(std::thread(consumer, i));
	}

	for (auto& t : producers) {
		t.join();
	}
	for (auto& t : consumers) {
		t.join();
	}
}