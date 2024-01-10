---
id: DataBaseParadigms
aliases:
  - Databases
  - Databases 
tags:
  - database
date: "2024-01-11"
title: Database_Paradigms
---

# Databases 
- Key Value Database (Redis, Memcached, Edcd)
- Wide Column Database (Cassandra, Hbase)

## Key Value Database
This type of paradigm mainly focuses on small chunks of data being cached for quick access. As the data is usually stored in a key-value format, this paradigm is often used for caching purposes.

```
key -> value 
```
Every value is associated with a key. Simple getting and setting of a value is done using a key.
This means query is not possible.

- Not suitable for large scale data 

## Wide Column Database 
A non-schema based database, That has a key-value pair structure. Each row has a key and a value. Whilst each row is also associated with a key.
```
key -> [columnKey1 -> value1, columnKey2 -> value2, columnKey3 -> value3]
```
Usually used in scenarios where there will be a lot of data to be stored, but not that many reads and updates 
So bulk data writing is usually preferred for example. Historical records, Time-series, High-Write, Low-Read scenarios

## Document 
A non-schema based database that has key-value pairs stored in a document format. Each document has a key and a value. The key-value pairs are stored in a document format. These documents are stored within a collections. Which can then be used to make a hierarchy of documents referencing eachother 

- Easy to use 
- Fails in scenario where data is connected but not related and updated often 

## Relational Database













