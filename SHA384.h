#pragma once
#include <bitset>
#include <sstream>
#include <iomanip>
#include "SHA384Utils.h"

template <typename T = std::string>
class SHA384
{
public:
    SHA384(T&&);

    T preprocessing(T);
    void hashComputation(T);

private:

};

template <typename T>
inline SHA384<T>::SHA384(T&& pmess)
{
    try
    {
        Message<std::string>::set_message(preprocessing(pmess));
        hashComputation(Message<std::string>::get_message());
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
}

template <typename T>
inline T SHA384<T>::preprocessing(T mess)
{
    try
    {
    std::stringstream ss;
    uint64_t l{ 8 * (uint64_t)mess.length() };
    uint64_t k{ (896 - (1 + l)) % 1024 };
    std::bitset<128>bits_view_of_mess_length(l);

    for (size_t i = 0; i < mess.length(); i++)
    {
        std::bitset<8> bitsView(mess[i]);
        ss << bitsView.to_string();
    }
    
    ss << '1';
    ss << std::setfill('0');
    ss << std::setw(k + 128) << bits_view_of_mess_length;
    
    return ss.str();
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;;
    }
}

template <typename T>
inline void SHA384<T>::hashComputation(T pmess)
{
    try
    {
    uint64_t a, b, c, d, e, f, g, h, t1, t2;
    uint64_t w[80];
    uint64_t H[8] =
    {
    0xcbbb9d5dc1059ed8, 0x629a292a367cd507, 0x9159015a3070dd17, 0x152fecd8f70e5939,
    0x67332667ffc00b31, 0x8eb44a8768581511, 0xdb0c2e0d64f98fa7, 0x47b5481dbefa4fa4
    };

    for (size_t i{}, j{}; i < pmess.length(); i += 64, ++j)
    {
        std::string word64_substr = pmess.substr(i, 64);
        std::bitset<64> word64_View(word64_substr);
        /*you can use this, but it is not works for zero-string -> std::stoll(word64_substr, 0, 2);*/
        w[j] = word64_View.to_ullong();

        if (j == 15)
        {
            for (j = 16; j < 80; ++j)
                w[j] = s1_512(w[j - 2]) + w[j - 7] + s0_512(w[j - 15]) + w[j - 16];
            j = -1;

            a = H[0];
            b = H[1];
            c = H[2];
            d = H[3];
            e = H[4];
            f = H[5];
            g = H[6];
            h = H[7];

            for (size_t t{}; t < 80; ++t)
            {
                t1 = h + S1_512(e) + CH(e, f, g) + K_512[t] + w[t];
                t2 = S0_512(a) + MAJ(a, b, c);
                h = g;
                g = f;
                f = e; 
                e = d + t1;
                d = c;
                c = b;
                b = a;
                a = t1 + t2;
            }

            H[0] += a;
            H[1] += b;
            H[2] += c;
            H[3] += d;
            H[4] += e;
            H[5] += f;
            H[6] += g;
            H[7] += h;
        }
    }

    std::stringstream ss;
    
    for (size_t i{}; i < 6; ++i)
        ss << std::setw(8) << std::setfill('0') << std::hex << H[i];
   
    Message<std::string>::set_digest(ss.str());
     return;
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
}
