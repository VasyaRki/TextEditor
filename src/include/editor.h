#ifndef EDITOR_H
#define EDITOR_H

#include <string>
#include <list>

class Editor {
public:
    Editor() : SIZE(0), buffer("") {
        CursorPos = _data.begin();
    }
    void Left() {
        if (CursorPos != _data.begin())
            CursorPos--;
    }   // сдвинуть курсор влево
    void Right() {
        if (CursorPos != _data.end())
            CursorPos++;
    }   // сдвинуть курсор вправо
    void Insert(char token) {
        CursorPos = _data.insert(CursorPos, token);
        CursorPos++;
        SIZE++;
    }   // вставить символ token
    void Copy(size_t tokens) {
        while (CursorPos != _data.end() && tokens--) {
            buffer += *CursorPos;
            CursorPos++;
        }
    }   // cкопировать
        // не более tokens символов,
        // начиная с текущей позиции курсора
    void Cut(size_t tokens) {
        buffer.clear();
        while (CursorPos != _data.end() && tokens--) {
            buffer += *CursorPos;
            CursorPos = _data.erase(CursorPos);
        }
    }   // вырезать не более tokens символов,
        // начиная с текущей позиции курсора
    inline void Paste() {
        for (size_t i = 0; i < buffer.size(); ++i) {
            CursorPos = _data.insert(CursorPos, buffer[i]);
            ++CursorPos;
        }
    }   // вставить содержимое буфера
        // в текущую позицию курсора
    std::string GetText() {
        std::string text;
        for (std::list<char>::const_iterator it = _data.begin(); it != _data.end(); ++it) {
            text += (*it);
        }
        return text;
    }
    // получить текущее содержимое
    // текстового редактора
private:
    std::list<char>::iterator CursorPos;
    size_t SIZE;
    std::list<char> _data;
    std::string buffer;
};

#endif // EDITOR_H