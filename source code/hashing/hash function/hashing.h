#pragma once

#include <cstdint>
#include <iostream>

template<typename T>
uint32_t hash(const T value);

template<>
uint32_t hash(const uint32_t value);

template<>
uint32_t hash(const int value);


uint32_t hash(char *value, size_t n);


template<typename T>
uint32_t hash(const T value)
{	
	return 0;
}

template<>
uint32_t hash(const uint32_t value)
{
	return (uint32_t)(~(value * 87178291199));
}

template<>
uint32_t hash(const int value)
{
	return hash((uint32_t)(value));
}

uint32_t hash(char *value, size_t n)
{
	int hashThis = 0;

	for (int i = 0; i < n; i++)
	{
		hashThis += ((int)(value[i])) * (i + 1);
	}

	return hash(hashThis);
}