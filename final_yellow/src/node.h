/*
 * node.h
 *
 *  Created on: 6 џэт. 2022 у.
 *      Author: SeltikeS
 */

#pragma once

#include "date.h"
#include <string>
#include <memory>


using namespace std;

enum class Comparison {
	  Less,
	  LessOrEqual,
	  Greater,
	  GreaterOrEqual,
	  Equal,
	  NotEqual
};

enum class LogicalOperation {
	And,
	Or
};

class Node {
public:
	virtual bool Evaluate(const Date& date, const string& event) const = 0;

	virtual ~Node() = default;

};

class EmptyNode : public Node {
public:
	EmptyNode() {}
	bool Evaluate(const Date& date, const string& event) const override;
};

class DateComparisonNode : public Node {
public:
	DateComparisonNode(Comparison cmp, const Date& date) : cmp_(cmp), date_(date) {}

	bool Evaluate(const Date& date, const string& event) const override;

private:
	const Comparison cmp_;
	const Date date_;
};

class EventComparisonNode : public Node {
public:
	EventComparisonNode(Comparison cmp, const string& event) : cmp_(cmp), event_(event) {}

	bool Evaluate(const Date& date, const string& event) const override;

private:
	const Comparison cmp_;
	const string event_;
};

class LogicalOperationNode : public Node {
public:
	LogicalOperationNode(LogicalOperation log_op, shared_ptr<Node> left, shared_ptr<Node> right) : op_(log_op), left_(left), right_(right) {}

	bool Evaluate(const Date& date, const string& event) const override;

private:
	LogicalOperation op_;
	shared_ptr<Node> left_;
	shared_ptr<Node> right_;
};
