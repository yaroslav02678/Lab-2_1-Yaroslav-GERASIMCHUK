# Виберіть базовий образ
FROM gcc:latest

# Встановіть робочу директорію
WORKDIR /app

# Скопіюйте файли проекту
COPY . .

# Встановіть CMake
RUN apt-get update && apt-get install -y cmake

# Створіть каталог для збірки
RUN mkdir build

# Перейдіть до каталогу збірки
WORKDIR /app/build

# Сконфігуруйте проект
RUN cmake ..

# Скомпілюйте проект
RUN make

# Запустіть програму (замініть "Lab-2_4-IDE-project" на ім'я вашого виконуваного файлу)
CMD ["./Lab-2_4-IDE-project"]
