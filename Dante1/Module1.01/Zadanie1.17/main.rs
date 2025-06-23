fn main()
{
    println!("Enter 10 numbers:");

    let mut input = String::new();
    std::io::stdin().read_line(&mut input).expect("Incorrect input");

    let mut parts = input.trim().split_whitespace();

    let x1: f32 = parts.next().expect("Less then 1").parse().expect("Incorrect number 1");
    let x2: f32 = parts.next().expect("Less then 2").parse().expect("Incorrect number 2");
    let x3: f32 = parts.next().expect("Less then 3").parse().expect("Incorrect number 3");
    let x4: f32 = parts.next().expect("Less then 4").parse().expect("Incorrect number 4");
    let x5: f32 = parts.next().expect("Less then 5").parse().expect("Incorrect number 5");
    let x6: f32 = parts.next().expect("Less then 6").parse().expect("Incorrect number 6");
    let x7: f32 = parts.next().expect("Less then 7").parse().expect("Incorrect number 7");
    let x8: f32 = parts.next().expect("Less then 8").parse().expect("Incorrect number 8");
    let x9: f32 = parts.next().expect("Less then 9").parse().expect("Incorrect number 9");
    let x10: f32 = parts.next().expect("Less then 10").parse().expect("Incorrect number 10");

    let y = (x1 + x2 + x3 + x4 + x5 + x6 + x7 + x8 + x9 + x10) / 10.0;

    println!("Result is = {:.4}", y);
}
