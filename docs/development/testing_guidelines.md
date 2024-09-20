# Testing Guidelines

This document contains the testing guidelines of this library. Any contributor
should follow this guidelines.

## Foreword

[Catch2](https://github.com/catchorg/Catch2) is used for unit testing the library,
make use of its features, such as:

* Use `TEST_CASE` and `SECTION` macros;
* Use [matchers](https://github.com/catchorg/Catch2/blob/v3.1.1/docs/matchers.md)
(if needed);
* Use [data generators](https://github.com/catchorg/Catch2/blob/v3.1.1/docs/generators.md)
(if needed);

... but:

* Do NOT create another `TEST_CASE` when a `SECTION` would suffice;
* Do NOT use [BDD-style test cases](https://github.com/catchorg/Catch2/blob/v3.1.1/docs/test-cases-and-sections.md#bdd-style-test-cases);

## General

* A test should only test one thing;
* A test should be short;
* Test should be able to run alone or all together in any order;
* Try to not use if / switch / for / while / etc., only use them if necessary;
* Avoid testing private / protected methods;

## Naming

A test should have the following name's structure:

* `<unit under test> should <expected result> when <condition>`, e.g.
`a transaction should throw when a thread is updated using a 'nullptr' handle`;

A section's name should have the following structure:

* `and <parameters>`; **OR**
* `using <parameters>`; **OR**
* `with <parameters>`;

## Tagging

[Catch2](https://github.com/catchorg/Catch2) can associate [tags](https://github.com/catchorg/Catch2/blob/v3.1.1/docs/test-cases-and-sections.md#tags)
with a test case. When creating a test case it must have:

* A tag related to the unit of work being tested, e.g. a test case for a class
named `my_cool_class` should be defined as `TEST_CASE("<NAME>", "[my_cool_class]<OTHER_TAGS>")`;
* A tag related to the method being tested, e.g. a test case for a function named
`my_func_1` in `my_cool_class` should be defined as `TEST_CASE("<NAME>", "[my_cool_class][my_func_1]")`;
