use regex::Regex;
fn main() // i didnt do tests for checking month-day-year 'cause its too easy 
{
    println!("Enter: ");

    let mut input = String::new();
    std::io::stdin().read_line(&mut input).expect("Error in String input");

    let input = input.trim();

    let re = Regex::new(r"^(\d+)-(\d+)-(\d+)$").expect("Error in regex transformation");

    if let Some(caps) = re.captures(input)
    {
        let day: i32 = caps[1].parse().expect("Day number");
        let month: i32 = caps[2].parse().expect("Month number");
        let year: i32 = caps[3].parse().expect("Year number");

        println!("Day number: {}", day);
        println!("Month number: {}", month);
        println!("Year number: {}", year);
    }
    else
    {
        println!("Incorrect input");
    }
}
