/*
 * node.cpp
 *
 *  Created on: 20 џэт. 2022 у.
 *      Author: SeltikeS
 */

#include "node.h"

bool EmptyNode::Evaluate(const Date& date, const string& event) const {
	return true;
}

bool DateComparisonNode::Evaluate(const Date& date, const string& event) const {
	switch(cmp_) {
		case Comparison::Equal :
			return date == date_;
		case Comparison::Greater :
			return date > date_;
		case Comparison::GreaterOrEqual :
			return date >= date_;
		case Comparison::Less :
			return date < date_;
		case Comparison::LessOrEqual :
			return date <= date_;
		case Comparison::NotEqual :
			return date != date_;
		default :
			throw  logic_error("Invalid logical operator in DateComparisonNode");
	}
}

bool EventComparisonNode::Evaluate(const Date& date, const string& event) const {
	bool result;
	switch(cmp_) {
		case Comparison::Equal :
			result = event == event_;
			break;
		case Comparison::Greater :
			result = event > event_;
			break;
		case Comparison::GreaterOrEqual :
			result = event >= event_;
			break;
		case Comparison::Less :
			result = event < event_;
			break;
		case Comparison::LessOrEqual :
			result = event <= event_;
			break;
		case Comparison::NotEqual :
			result = event != event_;
			break;
		default :
			throw  logic_error("Invalid logical operator in EventComparisonNode");
			return 0;
	}
	return result;
}

bool LogicalOperationNode::Evaluate(const Date& date, const string& event) const {
	switch(op_) {
		case LogicalOperation::And :
			return left_->Evaluate(date, event) && right_->Evaluate(date, event);
		case LogicalOperation::Or :
			return left_->Evaluate(date, event) || right_->Evaluate(date, event);
		default :
			throw logic_error("Invalid logical operator in LogicalOperationNode");
	}
}
