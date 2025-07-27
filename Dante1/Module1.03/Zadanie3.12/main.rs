fn main() {
    let mut result: i128 = 1;
    
    println!("Enter: ");
    
    let mut input: String = String::new();
    std::io::stdin().read_line(&mut input).expect("Err");
    let mut num: i32 = input.trim().parse().expect("err");
    
    if num < 0 || num >= 21 {
        panic!("Error!");
    }
    
    let mut point: i32 = 0;
    while point != num {
        result = result + result * point as i128;
        point += 1;
    }
    
    println!("{}", result);
}
