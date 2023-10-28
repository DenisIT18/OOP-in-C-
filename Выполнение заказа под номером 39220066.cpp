#include <iostream>
#include <string>
#include <locale>

class ItemOfAudio {
public:
    ItemOfAudio(const std::string& title, int duration) : title(title), duration(duration) {}

    virtual void play() {
        std::cout << "Играющая песня(трек): " << title << " (" << duration << " секунд)" << std::endl;
    }

    virtual std::string getInfo() const {
        return "Название " + title + ", Время проигрывания: " + std::to_string(duration) + " секунд";
    }

protected:
    std::string title;
    int duration;
};

class Song : public ItemOfAudio {
public:
    Song(const std::string& title, int duration, const std::string& singer) : ItemOfAudio(title, duration), singer(singer) {}

    void play() override {
        std::cout << "Проигрывающая песня(трек): " << title << " исполняющаяся: " << singer << " (" << duration << " секунд)" << std::endl;
    }

    std::string getInfo() const override {
        return "Песня - " + ItemOfAudio::getInfo() + " , Исполнитель " + singer;
    }

private:
    std::string singer;
};

class Podcast : public ItemOfAudio {
public:
    Podcast(const std::string& title, int duration, const std::string& host) : ItemOfAudio(title, duration), host(host) {}

    void play() override {
        std::cout << "Играющийся подкаст: " << title << " Выпущенный от: " << host << " (" << duration << " секунд)" << std::endl;
    }

    std::string getInfo() const override {
        return "Подкаст - " + ItemOfAudio::getInfo() + ", Автор: " + host;
    }

private:
    std::string host;
};

class AddNewSongs : public ItemOfAudio {
public:
    AddNewSongs(const std::string& title, int duration, int position, int n, bool add, const std::string& text) : ItemOfAudio(title, duration), position(position), n(n), add(add), text(text) {
        songs = new int[n];
        for (int i = 0; i < n; i++) {
            songs[i] = i + 1;
        }
    }

    void play() override {
        std::cout << "Названия песни(песен, треков): " << title << " Общее количество добавленных песен: " << duration << " Позиции  добавленных песен: " << position << " Добавилась ли песня: " << (add ? "Да" : "Нет") << " Текст песни: " << text << std::endl;
        std::cout << "Список песен:";
        for (int i = 0; i < n; i++) {
            std::cout << " " << songs[i];
        }
        std::cout << std::endl;
    }

    std::string getInfo() const override {
        std::string songList = "Список песен:";
        for (int i = 0; i < n; i++) {
            songList += " " + std::to_string(songs[i]);
        }

        return "Названия песни(песен, треков): " + title + " Общее количество добавленных песен: " + std::to_string(duration) + " Позиции  добавленных песен: " + std::to_string(position) + " Добавилась ли песня: " + (add ? "Да" : "Нет") + " Текст песни: " + text + "\n" + songList;
    }

    ~AddNewSongs() {
        delete[] songs;
    }

private:
    int position;
    int n;
    bool add;
    std::string text;
    int* songs;
};

class Composer : public ItemOfAudio {
public:
    Composer(const std::string& title, int experience) : ItemOfAudio(title, experience) {}

    void play() override {
        std::cout << "Композитор: " << title << " (Опыт: " << duration << " лет)" << std::endl;
    }

    std::string getInfo() const override {
        return "Композитор - " + ItemOfAudio::getInfo() + ", Опыт: " + std::to_string(duration) + " лет";
    }
};

class Instruments : public ItemOfAudio {
public:
    Instruments(const std::string& title, int id) : ItemOfAudio(title, id) {}

    void play() override {
        std::cout << "Инструмент: " << title << " (ID: " << duration << ")" << std::endl;
    }

    std::string getInfo() const override {
        return "Инструмент - " + ItemOfAudio::getInfo() + ", ID: " + std::to_string(duration);
    }
};

class Radiostation : public ItemOfAudio {
public:
    Radiostation(const std::string& title, int freq) : ItemOfAudio(title, freq) {}

    void play() override {
        std::cout << "Радиостанция: " << title << " (Частота: " << duration << " МГц)" << std::endl;
    }

    std::string getInfo() const override {
        return "Радиостанция - " + ItemOfAudio::getInfo() + ", Частота: " + std::to_string(duration) + " МГц";
    }
};

class Player : public ItemOfAudio {
public:
    Player(const std::string& title, int playlist, int currentPosition) : ItemOfAudio(title, playlist), currentPosition(currentPosition) {}

    void play() override {
        std::cout << "Плеер: " << title << " (Плейлист: " << duration << " песен, Текущая позиция: " << currentPosition << ")" << std::endl;
    }

    std::string getInfo() const override {
        return "Плеер - " + ItemOfAudio::getInfo() + ", Плейлист: " + std::to_string(duration) + " песен, Текущая позиция: " + std::to_string(currentPosition);
    }

private:
    int currentPosition;
};

class Album : public ItemOfAudio {
public:
    Album(const std::string& title, const std::string& artist, int year) : ItemOfAudio(title, year), artist(artist) {}

    void play() override {
        std::cout << "Альбом: " << title << " (Исполнитель: " << artist << ", Год выпуска: " << duration << ")" << std::endl;
    }

 std::string getInfo() const override {
    return "Альбом - " + ItemOfAudio::getInfo() + ", Исполнитель: " + artist + ", Год выпуска: " + std::to_string(duration);
}

private:
    std::string artist;
};

class Rating : public ItemOfAudio {
public:
    Rating(const std::string& title, int value) : ItemOfAudio(title, value) {}

    void play() override {
        std::cout << "Рейтинг песни: " << title << " (Значение: " << duration << ")" << std::endl;
    }

    std::string getInfo() const override {
        return "Рейтинг песни - " + ItemOfAudio::getInfo() + ", Значение: " + std::to_string(duration);
    }
};

int main() {
    std::setlocale(LC_ALL, "Russian");
    const int N = 9; 
    ItemOfAudio* audioItems[N];

    audioItems[0] = new Song("Песня 1", 180, "Исполнитель 1");
    audioItems[1] = new Podcast("Подкаст 1", 1200, "Ведущий 1");
    audioItems[2] = new AddNewSongs("Песня 2", 300, 2, 5, true, "Текст песни");
    audioItems[3] = new Composer("Композитор 1", 10);
    audioItems[4] = new Instruments("Гитара", 123);
    audioItems[5] = new Radiostation("Радиостанция 1", 98);
    audioItems[6] = new Player("Плеер 1", 50, 3);
    audioItems[7] = new Album("Альбом 1", "Исполнитель 2", 2000);
    audioItems[8] = new Rating("Песня 3", 5);

    for (int i = 0; i < N; i++) {
        audioItems[i]->play();
        std::cout << audioItems[i]->getInfo() << std::endl;
        delete audioItems[i];
    }

    return 0;
}



