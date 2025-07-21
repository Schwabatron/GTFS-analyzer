# GTFS Analyzer

**GTFS Analyzer** is a free, open-source tool for analyzing General Transit Feed Specification (GTFS) files.  
It allows you to run queries, export data to SQLite, and generate reports from unzipped GTFS datasets.

## Usage

```bash
gtfs-analyzer -i <input_folder> [--query <query_string>] [-o <output_directory>] [--export-db <path>]
