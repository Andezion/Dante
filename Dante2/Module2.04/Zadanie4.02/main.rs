fn main() {
    let mut number: Vec<f32> = Vec::new();
    number.push(std::f32::consts::PI);
    print!("{:.3} {:p}", number[0], &number[0]);
}
