// src/app/template.js

"use client";
import { useEffect } from "react";
import Link from "next/link";
export default function RootTemplate({ children }) {
	useEffect(() => {
		const colors = ["#FFE4E1", "#ADD8E6", "#90EE90"];
		const randomColor = colors[Math.floor(Math.random() * colors.length)];
		document.body.style.backgroundColor = randomColor;
	}, []);
	return (
		<div className="p-5">
			<nav className="mb-4">
				<h1 id="logo" className="text-2xl font-bold text-green-600">
					GeeksforGeeks
				</h1>
				<h3 className="text-lg font-bold">template.js | Next.js</h3>
				<Link href="/" className="text-sm underline block">
					Home
				</Link>
				<Link href="/about" className="text-sm underline block">
					About
				</Link>
			</nav>
			{children}
		</div>
	);
}
