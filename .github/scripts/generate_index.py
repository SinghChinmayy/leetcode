#!/usr/bin/env python3
"""
Script to automatically generate and update the README.md with solved LeetCode problems.
This script scans the Leetcode_Codes directory and generates a table of solved problems.
"""

import os
import re
from pathlib import Path
from typing import List, Tuple

# Extensions to consider as solutions
SOLUTION_EXTENSIONS = {'.cpp', '.py', '.java', '.js', '.ts', '.c', '.go', '.rs', '.sql'}

def extract_problem_number(filename: str) -> int:
    """Extract problem number from filename."""
    match = re.match(r'^(\d+)', filename)
    if match:
        return int(match.group(1))
    return float('inf')

def get_problems() -> List[Tuple[int, str, str]]:
    """
    Scan Leetcode_Codes directory and return list of solved problems.
    Returns list of (number, problem_name, file_path) tuples.
    """
    problems = []
    codes_dir = Path('Leetcode_Codes')
    
    if not codes_dir.exists():
        print(f"Warning: {codes_dir} directory not found")
        return problems
    
    # Dictionary to track problems we've already added (to avoid duplicates)
    seen_problems = {}
    
    for file_path in codes_dir.iterdir():
        if file_path.is_file() and file_path.suffix.lower() in SOLUTION_EXTENSIONS:
            filename = file_path.name
            problem_number = extract_problem_number(filename)
            
            # Skip if we've already added this problem number
            if problem_number in seen_problems:
                continue
                
            # Extract problem name (remove number and extension)
            problem_name = re.sub(r'^\d+\.\s*', '', filename)
            problem_name = Path(problem_name).stem
            
            seen_problems[problem_number] = True
            problems.append((problem_number, problem_name, str(file_path)))
    
    # Sort by problem number
    problems.sort(key=lambda x: x[0])
    return problems

def get_difficulty(problem_number: int) -> str:
    """
    Determine difficulty level based on problem number.
    This is a heuristic mapping. You may want to customize this.
    """
    # Common problem difficulty mapping (this is approximate)
    easy_problems = {7, 9, 70, 121, 136, 189, 283, 485, 509}
    medium_problems = {50, 176, 300}
    hard_problems = set()
    
    if problem_number in easy_problems:
        return "Easy"
    elif problem_number in medium_problems:
        return "Medium"
    elif problem_number in hard_problems:
        return "Hard"
    else:
        return "Unknown"

def generate_problems_table(problems: List[Tuple[int, str, str]]) -> str:
    """Generate markdown table for problems."""
    if not problems:
        return "No problems solved yet.\n"
    
    table = "| # | Problem | Difficulty | Solution |\n"
    table += "|---|---------|-----------|----------|\n"
    
    for problem_number, problem_name, file_path in problems:
        difficulty = get_difficulty(problem_number)
        # Get file extension
        ext = Path(file_path).suffix.lower()
        lang_map = {
            '.cpp': 'C++',
            '.py': 'Python',
            '.java': 'Java',
            '.js': 'JavaScript',
            '.ts': 'TypeScript',
            '.c': 'C',
            '.go': 'Go',
            '.rs': 'Rust',
            '.sql': 'SQL'
        }
        lang = lang_map.get(ext, 'Code')
        
        # Create markdown link with proper spacing
        file_link = file_path.replace(' ', '%20')
        solution_link = f"[{lang}](./{file_link})"
        
        table += f"| {problem_number} | {problem_name} | {difficulty} | {solution_link} |\n"
    
    return table

def update_readme(problems: List[Tuple[int, str, str]]):
    """Update README.md with the generated problems table."""
    readme_path = Path('README.md')
    
    if not readme_path.exists():
        print("Warning: README.md not found")
        return
    
    with open(readme_path, 'r', encoding='utf-8') as f:
        content = f.read()
    
    # Generate new problems section
    problems_table = generate_problems_table(problems)
    new_problems_section = f"""## Solved Problems

{problems_table}

**Total Problems Solved:** {len(problems)}
"""
    
    # Pattern to match the solved problems section
    pattern = r'## Solved Problems\n\n.*?\n\n\*\*Total Problems Solved:\*\*.*?\n'
    
    if re.search(pattern, content, re.DOTALL):
        # Replace existing section
        new_content = re.sub(pattern, new_problems_section, content, flags=re.DOTALL)
    else:
        # If section doesn't exist, insert before ## Notes & Resources
        notes_pattern = r'(## Notes & Resources)'
        if re.search(notes_pattern, content):
            new_content = re.sub(notes_pattern, new_problems_section + "\n" + r'\1', content)
        else:
            # Append at the end
            new_content = content + "\n" + new_problems_section
    
    with open(readme_path, 'w', encoding='utf-8') as f:
        f.write(new_content)
    
    print(f"✅ Updated README.md with {len(problems)} solved problems")

def main():
    """Main function."""
    problems = get_problems()
    update_readme(problems)
    
    if problems:
        print(f"Found {len(problems)} solved problems:")
        for num, name, path in problems:
            print(f"  {num}. {name} ({path})")

if __name__ == '__main__':
    main()
