use regex::Regex;
fn main()
{
    println!("Enter: ");

    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();

    let input = input.trim();

    let re = Regex::new(r"^([+-]?\d+)\s*([+-])i(\d+)$").unwrap();

    if let Some(caps) = re.captures(input)
    {
        let real: i32 = caps[1].parse().unwrap();
        let sign = &caps[2];
        let imag: i32 = caps[3].parse().unwrap();

        let imag = 
            if sign == "-"
            { 
                -imag 
            }
            else 
            { 
                imag 
            };

        println!("Real part: {}", real);
        println!("Imaginary part: {}", imag);
    }
    else
    {
        println!("Incorrect input");
    }
}
