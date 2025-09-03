fn compare(num1: i32, num2: i32, num3: i32) -> i32 {
    if num1 == num2 && num2 == num3 {
        return 1;
    }
    0
}

fn main() {
    let mut input: String  = String::new();
    println!("Enter: ");
    std::io::stdin().read_line(&mut input).expect("err");

    let mut numbers = input.trim().split_whitespace();

    let num1: i32 = numbers.next().expect("Нет первого числа").parse().expect("Ошибка парсинга");
    let num2: i32 = numbers.next().expect("Нет второго числа").parse().expect("Ошибка парсинга");
    let num3: i32 = numbers.next().expect("Нет третьего числа").parse().expect("Ошибка парсинга");

    if compare(num1, num2, num3) == 1 {
        println!("Equal");
    }
    else {
        println!("Not equal");
    }

}
