# Виберіть базовий образ
FROM gcc:latest

# Встановіть робочу директорію
WORKDIR /app

# Скопіюйте файли проекту
COPY . .

# Встановіть необхідні пакети, такі як CMake та інструменти для збірки, та очистіть кеш
RUN apt-get update && apt-get install -y cmake build-essential && rm -rf /var/lib/apt/lists/*

# Створіть каталог для збірки
RUN mkdir build

# Перейдіть до каталогу збірки
WORKDIR /app/build

# Запустіть CMake для конфігурації проекту
RUN cmake ..

# Скомпілюйте проект
RUN make

# Запустіть програму
CMD ["./Lab-2_4-IDE-project"]
