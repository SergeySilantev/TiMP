#pragma once
#include <vector>
#include <string>
#include <map>
#include <codecvt>
#include <locale>

/**
 * @brief Шифрование методом табличной перестановки
 * @details Ключ устанавливается в конструкторе,
 * а также с помощью метода set_key. Для зашифрования
 * и расшифрования предназначены методы encrypt и decrypt.
 * Метод set_tableform - вспомогающий. Методы: getValidKey, 
 * getValidOpenText, getValidCipherText - специализируются
 * на проверке входных данных.
 * @warning Реализация только для русского языка! С использованием wstring.
 */
 class TiMP ///Шифрование методом табличной перестановки
{
private:
	std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> codec;
	std::wstring numAlpha = L"АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";
	std::map <wchar_t,int> alphaNum;
	std::vector <int> key;
	std::vector<int> convert(const std::wstring& ws);
	std::wstring convert(const std::vector<int>& v);
	std::wstring getValidKey(const std::wstring & ws);
	std::wstring getValidOpenText(const std::wstring & ws);
	std::wstring getValidCipherText(const std::wstring & ws);
public:
	TiMP()=delete;
	TiMP(const std::wstring& wskey);
	std::wstring encrypt(const std::wstring& open_text);
	std::wstring decrypt(const std::wstring& cipher_text);
};
/**
 * @file Silantev.h
 * @brief Класс-исключение
 */
class cipher_error: public std::invalid_argument
{
public:
	explicit cipher_error (const std::string& what_arg):
        std::invalid_argument(what_arg) {}
            /**
	 * @brief Принимает строку, поднимает исключение
	 * @param what_arg
	 */

	explicit cipher_error (const char* what_arg):
		std::invalid_argument(what_arg) {}
        /**
	* @brief Принимает си строку, поднимает исключение
	* @param what_arg
	*/
};
