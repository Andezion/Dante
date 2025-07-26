fn main() {
    let mut power: i128 = 1;
    for i in 0..20 {
        println!("{} {}", i, power);
        power = power * 10;
    }
}
