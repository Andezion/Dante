fn quadratic_equation(a: f32, b: f32, c: f32, x: f32) -> f32 {
    a * x * x + b * x + c
}

fn main() {
    let mut input: String = String::new();

    println!("Enter: ");
    std::io::stdin().read_line(&mut input).expect("err");
    let mut numbers = input.split_whitespace();

    let num1: f32 = numbers.next().expect("Нет первого числа").parse().expect("Ошибка парсинга");
    let num2: f32 = numbers.next().expect("Нет второго числа").parse().expect("Ошибка парсинга");
    let num3: f32 = numbers.next().expect("Нет третьего числа").parse().expect("Ошибка парсинга");

    input.clear();

    std::io::stdin().read_line(&mut input).expect("err");
    let value: f32 = input.trim().parse().expect("err");

    println!("Result is: {}", quadratic_equation(num1, num2, num3, value));
}
