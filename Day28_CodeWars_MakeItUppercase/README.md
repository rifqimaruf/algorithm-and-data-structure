Its simple and you need to understand the basic knowledge of data tipe, first the const is constant, so you cant dirrectly modified it, also you cant compare the int with unsigned int, this happen when you try to get length of the const string with .lengt() it is otomatically turn into type of size_t, this type is unsigned integer.

This is another example of size_t
```
std::string::size_type length = myString.length();
```