# == Schema Information
#
# Table name: tools
#
#  id         :integer          not null, primary key
#  executable :string
#  help       :string
#  name       :string
#  tooltip    :string
#  parameters :text
#  created_at :datetime         not null
#  updated_at :datetime         not null
#

class Tool < ActiveRecord::Base
end
