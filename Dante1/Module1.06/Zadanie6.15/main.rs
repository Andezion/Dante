fn main() {
    let mut array:[[i32; 5]; 5] = [[0; 5]; 5];
    let mut sum1: i32 = 0;
    let mut sum2: i32 = 0;

    let mut input: String = String::new();
    println!("Enter: ");

    for i in 0..5 {
        for j in 0..5 {
            input.clear();
            std::io::stdin().read_line(&mut input).expect("Incorrect");
            array[i][j] = input.trim().parse().expect("Incorrect input");

            if i == j {
                sum1 = sum1 + array[i][j];
            }
            if i + j == 4 {
                sum2 = sum2 + array[i][j];
            }
        }
    }

    println!("{} {}", sum1, sum2);
}
