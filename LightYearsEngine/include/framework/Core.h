#pragma once

#include <cstdio>
#include <map>
#include <memory>
#include<unordered_map>

namespace ly
{
	 //same like poisoning with using namespace std?
	template<typename T>
	using uniquePtr = std::unique_ptr<T>; 

	template<typename T>
	using sharedPtr = std::shared_ptr<T>;

	template<typename T>
	using weakPtr = std::weak_ptr<T>;

	template<typename T>
	using ListArray = std::vector<T>;

	template<typename keyType, typename valType, typename Pr = std::less<keyType>>
	using Map = std::map<keyType, valType, Pr>;

	template<typename keyType, typename valType, typename hasher = std::hash<keyType>>
	using Dictionary = std::unordered_map<keyType, valType, hasher>;

	//Log Macro
	#define LOG(M, ...) printf(M "\n", ##__VA_ARGS__)

}
