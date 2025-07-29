fn main() {
    let mut max: f32 = f32::MAX;
    let mut min: f32 = f32::MIN;

    let mut sum: f32 = 0.0;
    let mut counter: i32 = 0;
    let mut input: String = String::new();
    println!("Enter: ");

    loop {
        input.clear();
        std::io::stdin().read_line(&mut input).expect("err");
        let temp: f32 = input.trim().parse().expect("err");

        if temp == -1.0 {
            break;
        }

        if max < temp {
            max = temp;
        }

        if min > temp || counter == 0 {
            min = temp;
        }

        sum = sum + temp;
        counter += 1;
    }

    println!("{} {} {}", min, max, sum / counter as f32);
}
