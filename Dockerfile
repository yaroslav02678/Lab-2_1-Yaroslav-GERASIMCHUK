# Вибір базового образу
FROM gcc:latest

# Встановіть робочу директорію
WORKDIR /app

# Скопіюйте всі файли вашого проекту до контейнера
COPY . .

# Скомпілюйте вашу програму
RUN g++ -o server main.cpp -lboost_system -lpthread

# Запустіть програму
CMD ["./Lab-2_4-IDE-project"]
