use indexmap::IndexMap;

fn main()
{
    let mut storage: IndexMap<i32, i32> = IndexMap::new();
    let mut counter: i32 = 0;
    
    println!("Enter: ");
    
    let mut input: String = String::new();
    while counter != 100
    {
        input.clear();
        std::io::stdin().read_line(&mut input).expect("Incorrect input");
        let key: i32 = input.trim().parse().expect("Incorrect input");
        
        if key == 0
        {
            break;
        }
        
        *storage.entry(key).or_insert(0) += 1;
        counter += 1;
        
    }
    
    for(_key, value) in &storage
    {
        if *value > 1
        {
            print!("{} ", _key);
        }
    }
    
    return;
}
