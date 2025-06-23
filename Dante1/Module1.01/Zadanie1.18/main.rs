fn main()
{
    println!("Enter 5 numbers:");

    let mut input = String::new();
    std::io::stdin().read_line(&mut input).expect("Incorrect input");

    let mut parts = input.trim().split_whitespace();

    let x1: f32 = parts.next().expect("Less then 1").parse().expect("Incorrect number 1");
    let x2: f32 = parts.next().expect("Less then 2").parse().expect("Incorrect number 2");
    let x3: f32 = parts.next().expect("Less then 3").parse().expect("Incorrect number 3");
    let x4: f32 = parts.next().expect("Less then 4").parse().expect("Incorrect number 4");
    let x5: f32 = parts.next().expect("Less then 5").parse().expect("Incorrect number 5");
    

    let y: f32 = (x1 + x2 + x3 + x4 + x5) / 5.0;

    println!("Result is = {:.4}", y);
}
