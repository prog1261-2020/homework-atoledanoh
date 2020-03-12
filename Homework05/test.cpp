/*
* @author  <Alejandro Toledano>
* @version <1.0>
*

* @section Academic Integrity
*  I certify that this work is solely my own and complies with
*  NBCC Academic Integrity Policy (policy 1111)
*
*
* @section DESCRIPTION
*  < Object Orientated Programming in C++ homework 05 inheritance with animal class >
*
*
* @section LICENSE
*  <any necessary attributions>
*
*  Copyright 2020
*  Permission to use, copy, modify, and/or distribute this software for
*  any purpose with or without fee is hereby granted, provided that the
*  above copyright notice and this permission notice appear in all copies.
*
*  THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
*  WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
*  MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
*  ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
*  WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
*  ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
*  OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
*
*/

#include "gtest/gtest.h"
#include "Cat.h"
#include "Dog.h"
#include "Duck.h"
#include <iostream>

TEST(TestCaseName, TestName) {
	//Animal cat("Sabrina", "cat", "miau");
	//Animal dog("Fido", "dog", "guau");
	//Animal duck("Donald J Duck", "duck", "cuac");

	Cat cat("Sabrina");
	Dog dog("Fido");
	Duck duck("Donald J Duck");

	std::cout << "\n\n";

	cat.speak();
	dog.speak();
	duck.speak();

	std::cout << "\n\n";

	EXPECT_EQ(1, 1);
	EXPECT_TRUE(true);
}