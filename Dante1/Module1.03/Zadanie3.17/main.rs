fn main() {
    let mut sum: f32 = 0.0;
    let mut pointer: u8 = 0;

    let mut input: String = String::new();
    println!("Enter: ");

    while pointer != 10 {
        input.clear();
        std::io::stdin().read_line(&mut input).expect("err");
        let mut temp: f32 = input.trim().parse().expect("err");

        if temp < 0.0 {
            temp = temp * -1.0;
        }

        sum = sum + temp;
        pointer += 1;
    }

    println!("{}", sum);
}
